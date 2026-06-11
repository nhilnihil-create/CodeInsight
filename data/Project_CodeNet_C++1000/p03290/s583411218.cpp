#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int d,g;
    cin >> d >> g;
    vector<int> num(d), bonus(d);
    for(int i=0; i<d; i++){
        cin >> num.at(i) >> bonus.at(i);
    }
    int ans=100000;
    for(int i=0; i<(1<<d); i++){
        vector<int> full(d,0);
        for(int j=0; j<d; j++){
            if(i & (1<<j)){
                full.at(j) = 1;
            }
        }
        int point=0;
        int solve=0;
        for(int j=0; j<d; j++){
            point+=((j+1)*100*num.at(j)+bonus.at(j))*full.at(j);
            solve+=num.at(j)*full.at(j);
        }
        if(point>=g) ans=min(ans,solve);
        else{
            //全部とかない奴の中の一番高い問題
            int k=0;
            for(int j=0; j<d; j++){
                if(full.at(j)==0) k=j;
            }
            if(point+(k+1)*100*(num.at(k)-1) >= g){
                solve += ((g-point)+((k+1)*100)-1)/((k+1)*100);
                ans = min(ans,solve);
            }
        }
    }
    cout << ans << endl;
}