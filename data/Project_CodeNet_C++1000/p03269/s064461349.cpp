
#include <time.h>

#include <stdlib.h>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
using namespace std;
#include <cstdint>
#include <vector>
#include <string>
int64_t pow(int64_t a,int64_t b){//a^bを求める
	if(b==0){
		return 1;
	}else{
		int64_t temp = pow(a,b/2);
		temp = temp * temp;
		if(b%2==1){
			temp = temp * a;
		}
		return temp;
	}
}
class Digit{
protected:
	int32_t m_base;
	std::vector<int32_t> m_digit;
public:
	class WrongBaseException{

	};

	Digit(const  int32_t base,const int64_t num):m_base(base){
		int64_t copy_num=num;
		while(true){
			int32_t temp=copy_num%m_base;
			m_digit.push_back(temp);
			copy_num=copy_num/base;
			if(copy_num<base){
				m_digit.push_back(copy_num);
				break;
			}
		}
	}
	Digit(const std::string& s){
		m_base=10;
		for(std::string::size_type i=s.size()-1;i>=0;--i){
			m_digit.push_back(std::atoi(&s[i]));
		}
	}
	Digit(const int32_t base,const std::vector<int32_t> digit):m_base(base),m_digit(digit){
	}
	std::vector<int32_t>* getDigit() const{
		vector<int32_t>* retval=new vector<int32_t>(m_digit);
		return retval;
	}
	operator int64_t() const{
		int64_t ans=0;
		for(std::vector<int32_t>::size_type i=0;i<m_digit.size();i++){
			ans+=pow(m_base,i)*m_digit.at(i);
		}
		return ans;
	}
	Digit& operator++(){
		(*this)+=Digit(m_base,1);
		return *this;
	}

	Digit& operator+=(const Digit& a){
		if(m_base!=a.m_base){
			throw WrongBaseException();
		}
		std::vector<int32_t> copy = m_digit;
		m_digit.clear();
		int32_t carry_up=0;
		for(std::vector<int32_t>::size_type i=0;i<std::max(copy.size(),a.m_digit.size());i++){
			int32_t temp_digit=0;
			if(i<copy.size()){
				temp_digit+=copy.at(i);
			}
			if(i<a.m_digit.size()){
				temp_digit+=a.m_digit.at(i);
			}
			temp_digit+=carry_up;
			carry_up=temp_digit/m_base;
			m_digit.push_back(temp_digit%m_base);
		}
		if(carry_up!=0){
			m_digit.push_back(carry_up);
		}
		return *this;
	}
	Digit operator+(const Digit& a) const{
		Digit retval(*this);
		retval+=a;
		return retval;;
	}
	Digit& operator-=(const Digit& a){
		if(m_base!=a.m_base){
			throw WrongBaseException();
		}
		if(m_digit.size()<a.m_digit.size()){
			throw std::underflow_error("Underflow in digit class");
		}
		std::vector<int32_t> copy=m_digit;
		m_digit.clear();
		int32_t carry_down=0;
		for(std::vector<int32_t>::size_type i=0;i<copy.size();i++){
			int32_t temp_digit=copy.at(i);
			if(i<a.m_digit.size()){
				temp_digit-=a.m_digit.at(i);
			}
			temp_digit-=carry_down;
			if(temp_digit<0){
				temp_digit+=m_base;
				carry_down=1;
			}else{
				carry_down=0;
			}
			m_digit.push_back(temp_digit);
		}
		if(carry_down>0){
			throw std::underflow_error("Underflow in digit class");
		}
		return *this;
	}
	Digit operator-(const Digit& a) const{
		Digit retval(*this);
		retval-=a;
		return retval;;
	}
	Digit& operator--(){
		(*this)-=Digit(m_base,1);
		return *this;
	}
};
struct edge{
	int32_t from;
	int32_t to;
	int32_t cost;
};
int main() {
	int32_t l;
	cin>>l;
	Digit dx(2,l);
	int32_t current_sum=0;
	vector<edge> ans;
	vector<int32_t> *d=dx.getDigit();

	int32_t ans_n=d->size();
	for(int32_t i=0;i<ans_n-1;i++){
		ans.push_back(edge{i+1,i+2,0});
		ans.push_back(edge{i+1,i+2,pow(2,i)});
	}
	current_sum=pow(2,ans_n-1);
	for(int32_t i=(d->size()-2);i>=0;i--){
		if(d->at(i)==1){
			ans.push_back(edge{i+1,ans_n,current_sum});
			current_sum+=(pow(2,i));
		}
	}

	cout<<ans_n<<" "<<ans.size()<<endl;
	for(auto i=ans.begin();i!=ans.end();i++){
		cout<<i->from<<" "<<i->to<<" "<<i->cost<<endl;
	}

	delete d;
	return 0;

}
