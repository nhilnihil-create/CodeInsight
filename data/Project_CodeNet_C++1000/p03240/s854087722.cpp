#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> x.at(i);
        cin >> y.at(i);
        cin >> h.at(i);
    }
    int real_x=0,real_y=0,real_h=0;
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            int check=0;
            bool ok=true;
            for(int k=0; k<n; k++){
                if(h.at(k)>0){
                    check = h.at(k) + abs(i-x.at(k)) + abs(j-y.at(k));
                }
            }
            //cout << check << endl;
            for(int k=0; k<n; k++){
                int calc;
                calc = max(0, check-abs(i-x.at(k))-abs(j-y.at(k)));
                if(calc != h.at(k)){
                    ok =false;
                    break;
                }
            }
            if(ok){
                real_x = i;
                real_y = j;
                real_h = check;
            }
        }
    }
    cout << real_x << " " << real_y << " " << real_h << endl;
}