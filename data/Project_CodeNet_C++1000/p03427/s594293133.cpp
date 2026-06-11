#include<bits/stdc++.h>
using namespace std;
 
int main(){
	string N;cin>>N;
 	int ans=0;
 	ans += (N[0]-'0')-1;
 	ans += 9 * (N.size() - 1);
 	int tmp = 0;
    for(int i=0;i<N.size();++i){
		tmp += N[i] - '0';
    }
 	cout << max(tmp,ans) << endl;
}