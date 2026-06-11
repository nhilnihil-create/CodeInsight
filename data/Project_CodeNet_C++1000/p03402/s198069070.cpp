#include <bits/stdc++.h>

using namespace std;
using ll =long long;
using db = double;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

#define che(a,string) cout<<"//"<<string <<"=="<<(a)<<"//" <<endl;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define leftunique(v) SORT(v);(v).erase(unique((v).begin(),(v).end()),(v).end())
//leftuniqueは配列から同じ要素のものを取り除く 例 4 6 2 1 3 4 1 2 なら 1 2 3 4 6 になる
bool IsInt(double a){int b = a/1;if(a==b){return true;}else {return false;}}
bool coY() {cout <<"Yes"<<endl;}
bool coN(){cout <<"No"<<endl;}
const int mod = 1e9 + 7;

ll ans;
//ここから書き始める
int main()
{
	cout << setprecision(10);
	int A , B;
	cin >> A >> B;//Aが白 B が黒
	vector<vector<char>> grid(100,vector<char> (100));
	rep(i,100){
		rep(j,100){
			if(j<50){
				grid[i][j]='.';
			}else{
				grid[i][j]='#';
			}
		}
	}
//	rep(i,100){
//		rep(j,100){
//			cout<<grid[i][j];
//		}
//		cout << endl;
//	}
	int white = 1;//Aにする
	int black = 1;//Bにする
	//blackから考えるか
	int i = 0, j =0;
	while(black<B){
		grid[i][j]='#';
		j+=2;
		black ++;
		if(j>=49){
			j = 0;
			i += 2;
		}
	}
	i = 0, j = 51;
	while(white<A){
		grid[i][j]='.';
		white ++;
		j += 2 ;
		if(j>=99){
			j = 51;
			i+=2;
		}
	}
	cout << 100<<" "<<100<<endl;
	rep(i,100){
		rep(j,100){
			cout<<grid[i][j];
		}
		cout << endl;
	}
}
