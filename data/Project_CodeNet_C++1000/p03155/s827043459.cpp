#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<limits>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;

typedef long long ll;
typedef string S;
typedef pair<int,int> P;

const int mod=1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,h,w;
    cin >> n >> h >> w;
    cout << (n-h+1)*(n-w+1) << endl;
    return 0;
}