#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    
    int x1[n]={};
    int y1[m]={};
    for(int i=0;i<n;i++){
        cin >> x1[i];
    }
    for(int i=0;i<m;i++){
        cin >> y1[i];
    }

    for(int z=x+1;z<y+1;z++){
        bool flag = true;

        for(int i=0;i<n;i++){
            if(x1[i]>=z) flag = false;
        }
        for(int i=0;i<m;i++){
            if(y1[i]<z) flag = false;
        }
        if(flag){
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
    return 0;
}

