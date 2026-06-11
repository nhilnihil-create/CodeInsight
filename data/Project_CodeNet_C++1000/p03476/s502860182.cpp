#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    
    vector<int>sv(100001,0);
    sv[0] = 0;sv[1]=0;
    
    for(int i = 2; i <=100000; i++){
        for (int j = i; j<=100000; j+=i) {
            if (sv[j]) {
             sv[j] = 2;
             continue;
            }
            sv[j] = 1;
        }
    }
    
    vector<int>a(sv.size(),0);
    for (int i = 0; i<a.size(); i++) {
        if (i % 2 == 0) continue;
        if(sv[i] == 1 && sv[(i+1)/2] == 1) a[i] = 1;
    }
    
    vector<int>sc(a.size()+1,0);
    for (int i = 0; i<a.size(); i++) {
        sc[i+1] = sc[i]+a[i];
    }

    int q;
    cin >> q;
    rep(i, 0, q){
        int l, r;
        cin >> l >> r;
        r++;
        cout << sc[r]-sc[l] << endl;
    }

    
  return 0;
}
