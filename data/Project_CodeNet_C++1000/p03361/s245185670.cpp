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

int row[]={0, 1, 0, -1};
int col[]={1, 0, -1, 0};

int main(){
	IOS
	cin >> h >> w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(arr[i][j]=='#'){
				bool bener=0;
				int baris, kolom;
				for(int k=0;k<4;k++){
					baris=i+row[k];
					kolom=j+col[k];
					if(arr[baris][kolom]=='#'){
						bener=1;
						break;	
					}
				}
				if(!bener){
					cout << "No" << '\n';
					return 0;
				}
			}
		}
	}
	cout << "Yes" << '\n';
}
