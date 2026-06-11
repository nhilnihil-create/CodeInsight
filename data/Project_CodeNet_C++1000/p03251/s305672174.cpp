#include "bits/stdc++.h"

using namespace std;


int main(){
    int N,M,X,Y;
    cin >> N>>M>>X>>Y;
    vector<int> a(N);
    vector<int> b(M);
    
    int XMAX=X;
    int YMIN=Y;

    for (int i=0;i<N;i++){
        cin>>a[i];
        XMAX=max(XMAX,a[i]);
    }

    for(int i=0;i<M;i++){
        cin >> b[i];
        YMIN=min(YMIN,b[i]);
    }


    if(XMAX < YMIN) cout << "No War" << endl;
    else cout << "War" << endl;

    return 0;


}