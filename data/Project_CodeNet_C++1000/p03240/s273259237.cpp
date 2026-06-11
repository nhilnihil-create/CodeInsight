#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int x[101], y[101];
    int h[101];
    int X,Y,H;
    for(int i=0;i<n;i++) {
        cin >> x[i] >> y[i] >> h[i];
        if(h[i] >= 1) {
            X = x[i];
            Y = y[i];
            H = h[i];
        }
    }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            int tmp = H+abs(X-i)+abs(Y-j);
            bool flag = true;
            for(int l=0;l<n;l++){
                int H2=tmp-abs(x[l]-i)-abs(y[l]-j);
                if(h[l] > 0 && h[l] != H2) flag = false;
                if(h[l] == 0 && H2 > 0) flag = false;
            }
            if(flag) {
                cout << i << " " << j << " " << tmp << endl;
            }
        }
    }
}
