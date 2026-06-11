#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int k, s;

	scanf("%d", &k);

	while(k%2==0){
		k=k/2;
	}
	while(k%5==0){
		k=k/5;
	}
	if(k==1){
		s=1;
	}else{

	set<int> res, res1, resr;

	for(int i=0; i<k; i++){
		res1.insert(i);
	}

	int r=1, d;
	for(d=0; d<k; d++){
		res.insert(r);
		r=10*r%k;
		if(r==1){
			break;
		}
	}
	d++;

	int x, e;
	while(!res1.empty()){
		auto itr=res1.begin();
		x=*itr;
		resr.insert(x);
		for(int i=0; i<d; i++){
			res1.erase(x);
			x=10*x%k;
		}
	}

	s=1;
	while(res.find(0)==res.end()){
		for(auto itr=resr.begin(); itr!=resr.end();itr++){
			x=*itr;
			e=0;
			if(x!=0){
				for(int i=0; i<d; i++){
					if(res.find(x-1)!=res.end()){
						e=1;
					}
					x=10*x%k;
				}
			}else{
				if(res.find(k-1)!=res.end()){
					e=1;
				}
			}
			if(e==1){
				for(int i=0; i<d; i++){
					res1.insert(x);
					x=10*x%k;
				}
			}
		}
		s++;
		while(!res1.empty()){
			auto itr1=res1.begin();
			int y=*itr1;
			res1.erase(itr1);
			res.insert(y);
		}
	}
	}

	printf("%d\n", s);
	return 0;

}