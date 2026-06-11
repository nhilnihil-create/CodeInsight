#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;




int main()
{
    int H,W,N,sr,sc;
    string S,T;
    cin >> H >> W >> N;
    cin >> sr >> sc;
    cin >> S;
    cin >> T;
    
    vector<char> ss = {'L','R','D','U'};
    vector<char> tt = {'R','L','U','D'};
    vector<int> a = {sc, sc, sr, sr};
    vector<int> bb = {W, W, H, H};
    vector<int> cc = {1, -1, -1, 1};
    
    for (int j = 0; j < 4; j++) {
         for (int i = 0; i < N; i++) {
             if (S[i] == ss[j]) a[j]-=cc[j];
             if(a[j] < 1 || a[j] > bb[j]){
                 cout << "NO" << endl;
                 return 0;
                 
             }
             if(T[i] == tt[j] && a[j]+cc[j] >= 1 && a[j]+cc[j] <= bb[j]) a[j] += cc[j];
             //cout << a[j] << " ";
         }
        //cout << endl;
    }
    
   
    
    cout << "YES" << endl;
    
    return 0;
}

