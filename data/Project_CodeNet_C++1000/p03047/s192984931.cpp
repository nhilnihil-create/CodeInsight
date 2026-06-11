#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7ll;

int n,k;
int cnt;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>n>>k;

for(int i=1; i<=n; i++){
	if(i+k-1<=n) cnt++;
}

cout<<cnt<<endl;

}

