#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;

queue<int> que;
vector<int> v(55556,0);

void pre(){
    queue<int> p;
    for(int i=2; i<55556; i++){
        if(v[i] == 0)   p.push(i);
        for(int j=i; j<55556; j+=i) v[j] = 1;
    }
    while(!p.empty()){
        int x = p.front();
        p.pop();
        if(x%5 == 1)    que.push(x);
    }
}
int main(){
    pre();
    int N;  cin >> N;
    for(int i=0; i<N; i++){
        cout << que.front() << " ";
        que.pop();
    }
}