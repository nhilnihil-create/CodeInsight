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
#define P pair<string, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int n;
    cin >> n;
    pair<P, int> p[n];
    rep(i, n){
        int s;
        cin >> p[i].first.first >> s;
        p[i].first.second = -s;
        p[i].second = i + 1;
    }
    sort(p, p + n);
    rep(i, n){
        cout << p[i].second << endl;
    }
}