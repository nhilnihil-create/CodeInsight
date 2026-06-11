#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	long long int a[1000000],b[1000000];
	long long ans=0,t,small = -1,r;
	for(int i=0;i<N;i++)
		cin >> a[i] >> b[i];
	for(int i=0;i<N;i++){
		if( a[i] > b[i] ){
            if(small > b[i]||small == -1){
                small =  b[i];
                r = i;
            }
		}
	}
	for(int i=0;i<N;i++)
		if( i != r ) ans += b[i];
	if(small==-1) cout << 0 << endl;
	else cout << ans << endl;
}

