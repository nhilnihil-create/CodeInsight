#include<iostream>
#include<algorithm>
#include<string>
#include<map>

#define req(i,n) for(i=0; i<(n); i++)
using namespace std;

int main()
{
	int i,n,m,tmp,max=0;
	map<string,int> count;
	string str;

	cin >> n;
	req(i,n){
		cin >> str;
		count[str]++;
	}

	cin >> m;
	req(i,m){
		cin >> str;
		count[str]--;
	}

	for(auto i = count.begin(); i != count.end(); i++){
		tmp = i->second;
		if(max < tmp)
			max = tmp;
	}
	cout << max << endl;
	
		

}
