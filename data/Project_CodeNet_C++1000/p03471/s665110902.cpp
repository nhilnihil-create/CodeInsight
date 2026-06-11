#include<bits/stdc++.h>
using namespace std; //std::の省略のため
using ll = long long;

int main(){
    int N, Y;
    cin >> N >> Y;

    int x, y, z;
    int ansx=0, ansy=0, ansz=0;

    for(x = 0; x <= N; x++){
        for(y = 0; y <= N-x; y++){
            z = N-x-y;
            if((10000*x + 5000*y + 1000*z) == Y){
                ansx = x;
                ansy = y;
                ansz = z;
                break;
            }
        }
    }

    if(ansx == 0 && ansy == 0 && ansz == 0){
        ansx = -1;
        ansy = -1;
        ansz = -1;
    }

    cout << ansx << " " << ansy << " " << ansz << " " << endl;
}