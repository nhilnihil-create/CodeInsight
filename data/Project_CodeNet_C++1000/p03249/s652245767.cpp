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
struct condition{
	int64_t vertex;
	int64_t total;
};
struct current{
	int64_t parent;
	int64_t vertex_num;
	int64_t sum;
};
struct edge{
	int64_t v1;
	int64_t v2;
};
bool operator< (const condition& a,const condition& b){
	return a.total>b.total;
}
int main() {

	int64_t n;
	cin>>n;
	std::vector<condition> cd;
	vector<edge> ans;
	ans.reserve(n);
	cd.reserve(n);
	for(int64_t i=0;i<n;i++){
		int64_t temp;
		cin>>temp;
		cd.push_back(condition{i+1,temp});
	}
	bool ans_possible=true;
	sort(cd.begin(),cd.end());
	map<int64_t,vector<current> > flow;
	for(auto i=cd.begin();i!=cd.end();i++){
		bool islast = (i==cd.end()-1);
		int64_t sum_vertex=0;
		int64_t total_cost=0;
		if(flow.count(i->total)){
			vector<current>& t=flow.at(i->total);

			for(auto k=t.begin();k!=t.end();k++){
				ans.push_back(edge{k->parent,i->vertex});
				sum_vertex+=(k->vertex_num);
				total_cost+=k->sum;
			}
			ans_possible=(total_cost==i->total);

			flow.erase(i->total);
		}else{
			ans_possible=false;
		}

		sum_vertex++;
		total_cost+=sum_vertex;

		int64_t parent_value=i->total-(n-2*sum_vertex);
		if(!islast&&parent_value>=i->total){
			ans_possible=false;
			break;
		}
		if(flow.count(parent_value)){
			flow.at(parent_value).push_back(current{i->vertex,sum_vertex,total_cost});
		}else{
			vector<current> temp2;
			temp2.push_back(current{i->vertex,sum_vertex,total_cost});
			flow.emplace(parent_value,temp2);
		}

	}
	if(flow.size()==1&&ans_possible&&ans.size()==(n-1)){
		for(auto i=ans.begin();i!=ans.end();i++){
			cout<<i->v1<<" "<<i->v2<<endl;
		}
	}else{
		cout<<-1<<endl;
	}





	return 0;

}
