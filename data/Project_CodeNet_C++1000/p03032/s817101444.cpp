#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    //A,B全探索
    int ans = 0;
    int suma = 0;
    vector<int>veca;
    for(int a=0;a<=min(n ,k);a++){//左からa個とる
        vector<int>vecb;
        if(a > 0){
            veca.push_back(v[a-1]);
            suma += v[a-1];
        }
        int sumb = 0;


        for(int b=0;a+b<=min(n,k);b++){//右からb個とる
            if(b > 0){
                vecb.push_back(v[n-b]);
                sumb += v[n-b];
            }
            if(veca.size() > 0){
                sort(veca.begin() ,veca.end());
            }if(vecb.size() > 0){
                sort(vecb.begin() ,vecb.end());
            }
            /*for(auto i :veca) cout << i << " ";
            cout << endl;
            for(auto i :vecb) cout << i << " ";
            cout << endl;*/

            int tmp = 0;
            int isum = suma + sumb;
            for(int i=0; tmp < k-(a+b) ;i++){
                if(i >= veca.size() && i >= vecb.size()) break;
                if(i >= veca.size()){
                    if(vecb[i] < 0) {
                    isum -= vecb[i];
                    tmp++;
                    }continue;
                }if(i >= vecb.size()){
                    if(veca[i] < 0) {
                    isum -= veca[i];
                    tmp++;
                    }continue;
                }

                if(veca[i] >= 0 && vecb[i] >= 0) break;
                if(tmp == k-(a+b)-1){
                    if(veca[i] < 0 && vecb[i] < 0){
                        isum -= min(veca[i] ,vecb[i]);
                        break;
                    }
                }

                if(veca[i] < 0) {
                    isum -= veca[i];
                    tmp++;
                }if(vecb[i] < 0) {
                    isum -= vecb[i];
                    tmp++;
                }
            }//cout << isum << endl;
            ans = max(ans ,isum);
        }
    }
    cout << ans << endl;
}