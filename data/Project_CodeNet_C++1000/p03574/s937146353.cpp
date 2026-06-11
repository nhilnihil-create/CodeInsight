#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
int h, w;
char arr[55][55];

int adj[]={1, 0, -1, 0, 1, 1, -1, -1};
int adj1[]={0, 1, 0, -1, -1, 1, 1, -1};

bool cek(int r, int c){
		if(r>0&&r<=h&&c>0&&c<=w&&arr[r][c]=='#'){
			return true;
		}
		return false;
	}

int main(){
	IOS
	cin >> h >> w;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin >> arr[i][j];
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(arr[i][j]=='#') continue;
			int ans=0;
			for(int k=0;k<8;k++){
				int row=i+adj[k];
				int col=j+adj1[k];
				if(cek(row, col)) ans++;
			}
			//cout << i << ' ' << j << ' ' << ans << '\n';
			arr[i][j]=ans+'0';
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cout << arr[i][j];
		}
		cout << '\n';
	}	
}
