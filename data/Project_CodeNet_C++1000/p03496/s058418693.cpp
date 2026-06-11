#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N){
        cin >> a[i];
    }
    vector<pair<int,int> > p(0);
    int a_max = -1000005;
    int max_pointer = 0;
    int a_min = 1000005;
    int min_pointer = 0;
    rep(i,N){
        if (a_max < a[i]){
            a_max = a[i];
            max_pointer = i;
        }
        if (a_min > a[i]){
            a_min = a[i];
            min_pointer = i;
        }
    }
    if (a_min >= 0){
        rep(i,N - 1){
            p.push_back(pair<int,int> (i + 1, i + 2));
        }
    }
    else if (a_max <= 0){
        rep(i,N - 1){
            p.push_back(pair<int,int> (N - i, N - i - 1));
        }
    }
    else{
        if (a_max + a_min >= 0){
            rep(i,N){
                p.push_back(pair<int,int> (max_pointer + 1, i + 1));
            }
            rep(i,N - 1){
                p.push_back(pair<int,int> (i + 1, i + 2));
            }
        }
        else{
            rep(i,N){
                p.push_back(pair<int,int> (min_pointer + 1, i + 1));
            }
            rep(i,N - 1){
                p.push_back(pair<int,int> (N - i, N - i - 1));
            }
        }
    }
    int len = p.size();
    cout << len << endl;
    rep(i,len){
        cout << p[i].first << " " << p[i].second << endl;
    }
}