#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF = 100000000;
int i,j,k,l,m;
ll mod=1000000007;

int main(){    
    string s;cin>>s;
    int k;cin>>k;
    map<string,int> x;//同じstringを数えないようにする
    
    vector<string> part_st;

    int n=s.size();
    if(n>5){n=5;}

    for(i=1;i<=n;i++){
        for(j=0;j<s.size()-i+1;j++){
            string t=s.substr(j,i);//j番目の後ろi文字を取り出す
            x[t]++;//count1のみpart_stにいれる
            if(x[t]==1){
                part_st.push_back(t);//長さk以下の部分列をpart_stに入れる(重複は許されないので1の時だけ)
            }
        }
    }
    
    sort(part_st.begin(),part_st.end());//長さk以下の部分列すべてをsort
    
    cout<<part_st[k-1]<<endl;
    return 0;
}