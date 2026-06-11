#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    vector<long int> x(N),y(N);
    vector<long int> h(N);

    for(int i=0;i<N;i++){
        cin >> x.at(i) >> y.at(i) >> h.at(i);
    }

    long int H;
    int ansx=0,ansy=0;

    for(long int cx=0;cx<=100;cx++){
        bool fin = true;
        for(long int cy=0;cy<=100;cy++){
            fin = true;    
            for(int i=0;i<N;i++){
                if(h.at(i)>0){
                H=h.at(i)+abs(x.at(i)-cx)+abs(y.at(i)-cy);
                break;
                }
            }

            for(int i=0;i<N;i++){
                if(h.at(i) == max((H-abs(x.at(i)-cx)-abs(y.at(i)-cy)),(long int)0)){
                }
                else{
                    fin = false;
                }
            }

            if(fin == true){
                ansx=cx;
                ansy=cy;
                break;
            }
        }
        if(fin == true)break;
    }

    cout << ansx << " " << ansy << " " << H << endl; 
}