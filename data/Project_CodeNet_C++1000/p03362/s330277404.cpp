#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
const double pi = 3.141592653589793;
//エラトステネスの篩による素数列挙 O(NloglogN)
vector<int> prime;
void Eratosthenes(int N){
    vector<int> arr(N+1);
	for(int i = 0; i <= N; i++){
		arr[i] = 1;
	}
	for(int i = 2; i *i <=N; i++){
		if(arr[i]){
			for(int j = 0; i * (j + 2) <= N; j++){
				arr[i *(j + 2)] = 0;
			}
		}
	}
    for(int i=2;i<=N;i++){
        if(arr[i]){
            prime.push_back(i);
        }
    }

}
int main(){
    int n;
    cin>>n;
    set<int> s;
    vector<int> ans;
    Eratosthenes(55555);
    int sum=0;
    int k=0;
    //5で割って1余る素数だけ入れてけばどの5個選んでも5の倍数だね
    //天才すぎる　かっけえ・・・・・(思いつかなった)
    while(ans.size()!=n){
        if(prime[k]%5==1){
            ans.push_back(prime[k]);
        }
        k++;
    }
    rep(i,n){
        cout<<ans[i]<<" ";
    }
}