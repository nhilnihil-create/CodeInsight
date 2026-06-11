#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int a, b;
    cin >> a >> b;
    if(a >= 13) cout << b << endl;
    else if(a <= 5) cout << 0 << endl;
    else cout << b / 2 << endl;
}