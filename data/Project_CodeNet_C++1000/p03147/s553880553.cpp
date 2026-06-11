#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    int full=0;
    for(int i=0; i<n; i++){
        cin >> h.at(i);
        full += h.at(i);
    }
    int count=0;
    int total=0;
    while(total<full){
        int l,r;
        l=0;r=n;
        for(int i=0; i<n; i++){
            if(h.at(i) >0){
                l = i;
                break;
            }
        }
        for(int i=l; i<n; i++){
            if(h.at(i) == 0){
                r=i;
                break;
            }
        }
        for(int i=l; i<r; i++){
            h.at(i)--;
        }
        total += r-l;
        count++; 
    }
    cout << count << endl;
}