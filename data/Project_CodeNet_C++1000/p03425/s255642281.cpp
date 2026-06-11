#include<iostream>
#include<string>
using namespace std;
int n;
string s[100000];
int cnt[5]={0};
long long cal_ans(){
    long long ans(0);
    for(int i(0);i<3;i++){
        for(int j(i+1);j<4;j++){
            for(int k(j+1);k<5;k++){
                ans += (long long)cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    return ans;
}
int main(void){
    cin>>n;
    for(int i(0);i<n;i++){
        cin>>s[i];
    }
    for(int i(0);i<n;i++){
        if(s[i][0] == 'M')cnt[0]++;
        else if(s[i][0] == 'A')cnt[1]++;
        else if(s[i][0] == 'R')cnt[2]++;
        else if(s[i][0] == 'C')cnt[3]++;
        else if(s[i][0] == 'H')cnt[4]++;
    }
    cout<<cal_ans()<<endl;
    return 0;
}