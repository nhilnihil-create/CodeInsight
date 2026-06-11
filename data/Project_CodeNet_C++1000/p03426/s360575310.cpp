#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W,D;
    cin >> H>> W>>D;
    vector<pair<int,int>> numbers(H*W);
    vector<vector<int>> boards(H);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int A;
            cin >> A;
            A--;
            boards[i].push_back(A);
            numbers[A].first = i;
            numbers[A].second = j;
        }
    }
    int Q;
    cin >> Q;
    vector<int> f(H*W,0);
    for(int i=D;i<(H*W);i++){
        f[i] = f[i-D] + abs(numbers[i].first-numbers[i-D].first) + abs(numbers[i].second-numbers[i-D].second); 
        // cerr <<"i=" <<i<<"f(i)="<<f[i] << endl;
    }
    
    for(int i=0;i<Q;i++){
        int L,R;
        cin >> L >>R;
        L--;R--;
        // cerr << "fR="<<f[R] << "fL=" << f[L] << endl;
        cout << f[R]-f[L] << "\n";
    }
    
    return 0;
}