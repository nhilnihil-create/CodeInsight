#include <bits/stdc++.h>
using namespace std;

int dist(int p, int q){
    if( p >= q) return p-q;
    else return q-p;
}

int main(){
    int a, b, c ,d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    bool ans = false;
    if(dist(a,b) > k) ans =true;
    if(dist(a,c) > k) ans =true;
    if(dist(a,d) > k) ans =true;
    if(dist(a,e) > k) ans =true;
    if(dist(b,c) > k) ans =true;
    if(dist(b,d) > k) ans =true;
    if(dist(b,e) > k) ans =true;
    if(dist(c,d) > k) ans =true;
    if(dist(c,e) > k) ans =true;
    if(dist(d,e) > k) ans =true;
    


    if(ans) cout << ":(" << endl;
    else cout << "Yay!" << endl;
}