#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int mx2[] = {1,0};
int my2[] = {0,1};
#define pb push_back 

int main(){
    int h,w; cin >> h >> w;
    vector<vector<int>> a(h+2,vector<int> (w+2));
    rep(i,h+2) rep(j,w+2) a[i][j] = -1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> a[i][j];
        }
    }

    vector<int> ansy,ansx,ansxd,ansyd;

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(a[i][j] % 2 != 0 && a[i][j] > 0){
                rep(k,2){
                    if(a[i+my2[k]][j+mx2[k]] >= 0){
                        a[i+my2[k]][j+mx2[k]]++;
                        a[i][j]--;
                        ansy.push_back(i);
                        ansx.push_back(j);
                        ansyd.push_back(i+my2[k]);
                        ansxd.push_back(j+mx2[k]);
                        break;
                    }
                }
            }
        }
    }

    int n = ansy.size();
    cout << n << endl;
    rep(i,n){
        cout << ansy[i] << " " << ansx[i] << " " << ansyd[i] << " " << ansxd[i] << endl; 
    }
}