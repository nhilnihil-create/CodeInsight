
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

int main() {
	int32_t n;
	cin>>n;
	int32_t *max_speed=new int32_t[n+2];
	int32_t *time=new int32_t[n+1];
	time[0]=0;
	for(int32_t i1=0;i1<n;i1++){
		int32_t temp;
		cin>>temp;
		time[i1+1]=time[i1]+temp;
	}
	max_speed[0]=0;
	max_speed[n+1]=0;
	for(int32_t i1=0;i1<n;i1++){
		cin>>max_speed[i1+1];
	}
	int32_t *forward_limit=new int32_t[n+1];
	forward_limit[0]=0;
	for(int32_t i1=1;i1<n+1;i1++){
		forward_limit[i1]=min(forward_limit[i1-1]+(time[i1]-time[i1-1]),max_speed[i1]/*,max_speed[i1+1]*/);
		forward_limit[i1]=min(forward_limit[i1],max_speed[i1+1]);
	}
	int32_t *backward_limit=new int32_t[n+1];
	backward_limit[n]=0;
	for(int32_t i1=n-1;i1>=0;i1--){
		backward_limit[i1]=min(backward_limit[i1+1]+(time[i1+1]-time[i1]),max_speed[i1]/*,max_speed[i1+1]*/);
		backward_limit[i1]=min(backward_limit[i1],max_speed[i1+1]);

	}
	double ans=0;
	for(int32_t i1=0;i1<n;i1++){
		int32_t left_limit=min(forward_limit[i1],backward_limit[i1]);
		int32_t right_limit=min(forward_limit[i1+1],backward_limit[i1+1]);
		if(left_limit==max_speed[i1+1]){
			if(right_limit==max_speed[i1+1]){
				ans+=max_speed[i1+1]*(time[i1+1]-time[i1]);
			}else{
				ans+=max_speed[i1+1]*(time[i1+1]-time[i1])-0.5*((max_speed[i1+1]-right_limit)*(max_speed[i1+1]-right_limit));
			}
		}else{
			if(right_limit==max_speed[i1+1]){
				ans+=max_speed[i1+1]*(time[i1+1]-time[i1])-0.5*((max_speed[i1+1]-left_limit)*(max_speed[i1+1]-left_limit));
			}else{
				if(2*max_speed[i1+1]-left_limit-right_limit<time[i1+1]-time[i1]){
					ans+=max_speed[i1+1]*(time[i1+1]-time[i1])-0.5*((max_speed[i1+1]-left_limit)*(max_speed[i1+1]-left_limit))-0.5*((max_speed[i1+1]-right_limit)*(max_speed[i1+1]-right_limit));
				}else{
					double peek_speed=(left_limit+right_limit)*0.5+(time[i1+1]-time[i1])*0.5;
					double peek_time=peek_speed-left_limit;
					ans+=(left_limit+peek_speed)*peek_time*0.5+(right_limit+peek_speed)*(time[i1+1]-time[i1]-peek_time)*0.5;
				}
			}
		}
	}
	cout<<fixed<<setprecision(8);
	cout<<ans<<endl;

}
