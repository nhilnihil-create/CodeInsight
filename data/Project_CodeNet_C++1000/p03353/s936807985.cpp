#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	string line;
	cin >> line;

	int K;
	scanf("%d",&K);

	vector<string> V;

	int maximum = min(K,(int)line.length());

	for(int len = 1; len <= maximum ; len++){

		for(int left = 0; left+len-1 < line.length(); left++){
			string work;
			for(int i = 0; i < len; i++){

				work += line[left+i];
			}
			V.push_back(work);
		}
	}

	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());

	/*for(int i = 0; i < V.size(); i++){

		printf("V[%d]:%s\n",i,V[i].c_str());
	}*/

	printf("%s\n",V[K-1].c_str());

	return 0;
}
