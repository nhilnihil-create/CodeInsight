#include <bits/stdc++.h>
using namespace std;
 
string D = "UDLR";
void fail(){
    cout << "NO" << endl;
    exit(0);
}
 
int main(){
    int H, W, N;
    cin >> H >> W >> N;
    int sr, sc;
    cin >> sr >> sc;
    sr--; sc--;
    string Ss, Ts;
    cin >> Ss >> Ts;
    int S[200000], T[200000];
    for(int i=0; i<N; i++){
        S[i] = D.find(Ss[i]);
        T[i] = D.find(Ts[i]);
    }
 
    for(int t=0; t<2; t++){
        int add = 2*t+1, sub = 2*t;
        int start = (t==0 ? sr : sc);
        int X = (t==0 ? H : W);
        int mx = X-1, mn = 0;
        for(int i=N-1; i>=0; i--){
            if(T[i] == sub){
                mx = min(X-1, mx+1);
            }else if(T[i] == add){
                mn = max(0, mn-1);
            }
            if(S[i] == add){
                mx--;
            }else if(S[i] == sub){
                mn++;
            }
            if(mn > mx) fail();
        }
        if(!(mn <= start && start <= mx)) fail();
    }
    cout << "YES" << endl;
    return 0;
}