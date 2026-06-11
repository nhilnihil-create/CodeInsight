#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    //vector<int> x(N),y(N),h(N);
    vector<vector<int>> hxy(N,vector<int>(3));
    for ( int i = 0; i < N; ++i){
        cin >> hxy[i][1] >> hxy[i][2] >> hxy[i][0];
    }
    
    //sort(hxy.begin(),hxy.end(),greater<int>());
    sort(hxy.begin(),hxy.end());
    reverse(hxy.begin(),hxy.end());
    
    /*for ( vector<int> p : hxy ){
        cout << p[0] << " " << p[1] << " " << p[2] << endl;
    }*/
    
    
    int ansx = 0;
    int ansy = 0;
    int ansh = 0;
    for ( int cx = 0; cx <= 100; ++cx){
        for ( int cy = 0; cy <= 100; ++cy){
            int h;
            h = hxy[0][0] + abs(cx-hxy[0][1]) + abs(cy-hxy[0][2]);
            bool flg = true;
            for ( int i = 1; i < N; ++i){
                int hi;
                hi = max( h - abs(cx-hxy[i][1]) - abs(cy-hxy[i][2]),0);
                if ( hi != hxy[i][0] ) {
                    flg = false;
                    break;
                }
            }
            if ( flg ){
                ansx = cx;
                ansy = cy;
                ansh = h;
            }
        }
    }
    cout << ansx << " " << ansy << " " << ansh << endl;
    
    return 0;
}