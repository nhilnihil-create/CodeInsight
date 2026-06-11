#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
int input(int n){
    string ss[] = {"Vacent", "Male", "Female"};
    cout << n << endl;
    string str;
    cin >> str;
    if(str == ss[0])exit(0);
    if(str == ss[1])return 1;
    else return 2;
    
}
main(){
    int N;
    cin >> N;
    
    int l = 0, r = N-1;
    int vl = input(l), vr = input(r);
    while(r - l >= 3){
        //[l,r]→[l,k], [k,r]
        int k = (l + r) / 2;
        int vk = input(k);
        //[l,k]にVacentがあるとき
        if(((k-l) % 2 == 0) ^ (vl == vk) ){
            r = k;
            vr = vk;
        }else{
            l = k;
            vl = vk;
        }
    }
    //cout << l << "," << vl << ":" << r << "," << vr << endl;
    input((l + r) / 2);
    cerr << "error!" << endl;
}