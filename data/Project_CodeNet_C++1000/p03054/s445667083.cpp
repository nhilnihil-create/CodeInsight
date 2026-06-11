#include <bits/stdc++.h>
using namespace std;

void fail(){
    cout << "NO" << endl;
    exit(0);
}

int main(){
    int H, W, N, sr, sc;
    cin >> H >> W >> N >> sr >> sc;
    sr--; sc--;
    string S, T;
    cin >> S >> T;

    string LRUD = "LRUD";
    int dx[] = {-1, 1, 0, 0};
    for(int t=0; t<2; t++){
        int mn = 0, mx = W-1;
        for(int i=N-1; i>=0; i--){
            int c1 = LRUD.find(T[i]);
            if(dx[c1] == 1) mn = max(mn-1, 0);
            if(dx[c1] == -1) mx = min(mx+1, W-1);
            int c2 = LRUD.find(S[i]);
            if(dx[c2] == 1) mx--;
            if(dx[c2] == -1) mn++;
            if(mn > mx) fail();
        }

        if(!(mn <= sc && sc <= mx)) fail();
        swap(H, W);
        swap(sr, sc);
        swap(dx[0], dx[2]);
        swap(dx[1], dx[3]);
    }
    cout << "YES" << endl;
}