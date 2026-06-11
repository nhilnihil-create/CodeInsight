
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
struct Interval{
	int64_t left;
	int64_t right;
	bool used=false;
};

bool left_op(const Interval* a,const Interval* b){
	return a->left>b->left;
}
bool right_op(const Interval* a,const Interval* b){
	return a->right<b->right;
}
int main(){
	vector<Interval*> left_sort;
	vector<Interval*> right_sort;
	int64_t n;
	cin>>n;
	for(int64_t i1=0;i1<n;i1++){
		int64_t left,right;
		cin>>left>>right;
		Interval* temp=new Interval{left,right,false};
		left_sort.push_back(temp);
		right_sort.push_back(temp);
	}
	sort(left_sort.begin(),left_sort.end(),left_op);
	sort(right_sort.begin(),right_sort.end(),right_op);
	int64_t left_index=0;
	int64_t right_index=0;
	int64_t candidate1=0;
	bool way=true;
	int64_t current_pos=0;
	bool finished=false;
	while(true){
		if(way){
			int64_t temp=left_index;
			while(!finished&&left_sort[temp]->used){
				temp++;
				if(temp==left_sort.size()){
					finished=true;
				}
			}
			if(finished||left_sort[temp]->left<=current_pos){
				candidate1+=labs(current_pos);
				break;
			}else{
				left_sort[temp]->used=true;
				way=false;
				candidate1+=labs(left_sort[temp]->left-current_pos);
				left_index=temp;
				current_pos=left_sort[temp]->left;
			}

		}else{
			int64_t temp=right_index;
			while(!finished&&right_sort[temp]->used){
				temp++;
				if(temp==right_sort.size()){
					finished=true;
					break;
				}
			}
			if(finished||right_sort[temp]->right>=current_pos){
				candidate1+=labs(current_pos);
				break;
			}else{
				right_sort[temp]->used=true;
				way=true;
				candidate1+=labs(right_sort[temp]->right-current_pos);
				right_index=temp;
				current_pos=right_sort[temp]->right;
			}
		}
	}
	left_index=0;
	right_index=0;
	int64_t candidate2=0;
	way=false;
	current_pos=0;
	finished=false;
	for(auto i=left_sort.begin();i!=left_sort.end();i++){
		Interval* temp=(*i);
		temp->used=false;
	}
	while(true){
		if(way){
			int64_t temp=left_index;
			while(!finished&&left_sort[temp]->used){
				temp++;
				if(temp==left_sort.size()){
					finished=true;
				}
			}
			if(finished||left_sort[temp]->left<=current_pos){
				candidate2+=labs(current_pos);
				break;
			}else{
				left_sort[temp]->used=true;
				way=false;
				candidate2+=labs(left_sort[temp]->left-current_pos);
				left_index=temp;
				current_pos=left_sort[temp]->left;
			}

		}else{
			int64_t temp=right_index;
			while(!finished&&right_sort[temp]->used){
				temp++;
				if(temp==right_sort.size()){
					finished=true;
					break;
				}
			}
			if(finished||right_sort[temp]->right>=current_pos){
				candidate2+=labs(current_pos);
				break;
			}else{
				right_sort[temp]->used=true;
				way=true;
				candidate2+=labs(right_sort[temp]->right-current_pos);
				right_index=temp;
				current_pos=right_sort[temp]->right;
			}
		}
	}
	cout<<std::max(candidate1,candidate2)<<endl;


}