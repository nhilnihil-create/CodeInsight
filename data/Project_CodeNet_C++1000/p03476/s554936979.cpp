#include <bits/stdc++.h>
using namespace std;
const int INF = 101010;

int main(){
    int sqt = ceil(sqrt(INF) + 0.1);
    vector<int> a(INF, 1);
  	a[0] = 0; a[1] = 0;
    for(int i=0; i<sqt; ++i){
        if(!a[i]){continue;}
        for(int j=i*2; j<INF; j+=i){a[j] = 0;}
    }

    vector<int> like(INF, 0);
    for(int i=0; i<INF; ++i){
        if(i%2==0){continue;}
        if(a[i] && a[(i+1)/2]){like[i] = 1;}
    }
    vector<int> s(INF, 0);
    for(int i=0; i<INF; ++i){
        s[i+1] = s[i] + like[i];  	
    }

  	int q; cin >> q;
    for(int i=0; i<q; ++i){
        int l, r; cin >> l >> r;
        cout << s[r+1] - s[l] << endl;
    }

    return 0;
}