#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<vector<int>> point(n,vector<int>(3));
	vector<int> hoge={-1,-1,-1};
	for(int i=0;i<n;i++) {
		cin>>point.at(i).at(0)>>point.at(i).at(1)>>point.at(i).at(2);
		if(point.at(i).at(2)>=1) hoge=point.at(i);
	}

	for(int x=0;x<=100;x++){
		for(int y=0;y<=100;y++){
			int preH=hoge.at(2)+abs(x-hoge.at(0))+abs(y-hoge.at(1));
			bool flag=true;

			for(auto a:point){
				int pre=preH-abs(x-a.at(0))-abs(y-a.at(1));
				pre=max(pre,0);

				if(pre!=a.at(2)){
					flag=false;
					break;
				}
			}

			if(flag){
				cout<<x<<" "<<y<<" "<<preH<<endl;
				goto END;
			}
		}
	}

	END:

	return 0;
}
