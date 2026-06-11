#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
    cin >> s;
    int n = s.size();
    s = '.' + s;
    bool exist = true;
    if(s[1]=='0' || s[n]=='1')exist = false;

    for(int i=1;i<n;i++){
        if(s[i]!=s[n-i])exist = false;
    }
    if(!exist){
		cout << -1 << endl;
		return 0;
	}
    s[n] = '1';
    queue<int> ones;
    for(int i=1;i<=n;i++){
        if(s[i]=='1')ones.push(i);
    }
    for(int i=1;i<n;i++){
        if(i==ones.front()){
            ones.pop();
        }
        cout << i << " " << ones.front() << endl;
    }
}