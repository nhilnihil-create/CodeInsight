#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N,T,tmp_cost,tmp_time;
  	int cost_min=20000;
	std::vector<int> time,cost;
  
 	cin >> N >> T;
	for(int i=0;i<N;i++){
    	cin >> tmp_cost >> tmp_time;
      	cost.push_back(tmp_cost);
      	time.push_back(tmp_time);
    }
  	for(int j=0;j<N;j++){
    	if(cost[j] < cost_min && time[j] <= T){
        	cost_min = cost[j];
        } 
    }
  	if(cost_min!=20000){
    	cout << cost_min <<endl;
    }else{ cout << "TLE" << endl;}
	return 0;
}