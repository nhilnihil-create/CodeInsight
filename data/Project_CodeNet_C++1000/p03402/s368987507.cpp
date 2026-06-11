#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> Pint;
typedef pair<ll, ll> P;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
ll MOD  = 1000000007;
vector<int> dy = {0,0,1,-1};
vector<int> dx = {1,-1,0,0};

int main(void){
    cin.tie(0);
   	ios::sync_with_stdio(false);
   	int A, B;
   	cin >> A >> B;
   	
   	vector<vector<char>> mp(100, vector<char>(100));
   	for(int i = 0; i < 100; i++){
   	    for(int j = 0; j < 100; j++){
   	        if(i < 50){
   	            mp[i][j] = '.';
   	        }else{
   	            mp[i][j] = '#';
   	        }
   	    }
   	}
   	
   	for(int i = 0; i < B - 1; i++){
   	    mp[(i / 50) * 2][(i % 50) * 2] = '#';
   	}
   	for(int i = 0; i < A - 1; i++){
   	    mp[(i / 50) * 2 + 51][(i % 50) * 2] = '.';
   	}
   	cout << 100 << " " << 100 << endl;
   	for(int i = 0; i < 100; i++){
   	    for(int j = 0; j < 100; j++){
   	        cout << mp[i][j];
   	    }
   	    cout << endl;
   	}
}

