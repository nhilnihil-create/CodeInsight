
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
#include <set>
#include <iomanip>
#include <numeric>

using namespace std;
int64_t gcd(int64_t a,int64_t b){
	if(a==0){
		return b;
	}else if(b==0){
		return a;
	}else if(a>b){
		return gcd(a%b,b);
	}else{
		return gcd(b%a,a);
	}
}
int main(){
	int32_t n;
	cin>>n;
	for(int32_t loop=0;loop<n;loop++){
		int64_t a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a<b){
			cout<<"No"<<endl;
			continue;
		}
		if(b>d){
			cout<<"No"<<endl;
		}else if(b==d){
			if(a%b<=c){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}else if(c>=b){
			cout<<"Yes"<<endl;
		}else{
			int64_t step=gcd(b,d);
			if(a%b>c){
				cout<<"No"<<endl;
			}else if(c>=b-1){
				cout<<"Yes"<<endl;
			}else if(b-1-c>=step){
				cout<<"No"<<endl;
			}else if((c-(a%b))%step<(b-1-(a%b))%step){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}
	}



}