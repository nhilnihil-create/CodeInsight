// Hanadstand
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX=1e5+5;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a=0;
    int b=0;
    int v[MAX][3];
    for(int i=0; i<MAX; i++){
        v[i][0]=0; 
        v[i][1]=0;
        v[i][2]=0;
    }
    int j=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='1' && (s[i+1]=='0' || i==s.size()-1)){
            a++;
            v[j][2]=a;
            j++;
            v[j][0]=a;
            a=0;
        }
        else if(s[i]=='0' && (s[i+1]=='1' || i==s.size()-1)){
            b++;
            v[j][1]=b;
            b=0;
        }
        else if(s[i]=='1' && s[i+1]=='1'){a++;}
        else if(s[i]=='0' && s[i+1]=='0'){b++;}
    }
    vector<ll> sum(j+1);
    for(int i=0; i<=j; i++){
        for(int t=0; t<k; t++){
            if((i+t)>j){
                break;
            }
            sum[i]+=v[i+t][1]+v[i+t][2];
            if((t)==0){
                sum[i]+=v[i+t][0];
            }
        }
    }

    sort(sum.begin(), sum.end(), greater<ll>());

    cout << sum[0] << endl;
    return 0;
}