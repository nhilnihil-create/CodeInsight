#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
#include<bitset>
#include<string>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;
int mpown(int m,int n);
int bitCount(int bits);
int main(){
    int n,a,b,c;
    cin >> n>>a>>b>>c;
    vector<int> l(n);
    for(int i=0;i<n;i++)cin >> l.at(i);
    // sort(l.begin(),l.end());
    int fora,forb,forc;
    int foran,forbn,forcn;
    vector<int> cond(n,0);
    int minmp=1000*10;
    int mp;
    // cout << "a " << endl;
    for(int i=0;i<mpown(4,n);i++){
        int pos=0;
        while(i!=0){
            if(cond.at(pos)!=3){
                cond.at(pos)++;
                break;
            }
            else{
                cond.at(pos)=0;
                pos++;
            }
        }
        fora=0;forb=0;forc=0;
        foran=0;forbn=0;forcn=0;
        for(int i=0;i<n;i++){
            if(cond.at(i)==1){
                fora+=l.at(i);foran++;
            }else if(cond.at(i)==2){
                forb+=l.at(i);forbn++;
            }else if(cond.at(i)==3){
                forc+=l.at(i);forcn++;
            }
            
        }
        if(foran*forbn*forcn==0)continue;
        mp=(abs(fora-a)+(foran-1)*10)+(abs(forb-b)+(forbn-1)*10)+(abs(forc-c)+(forcn-1)*10);
        if(minmp > mp)minmp=mp;
    }
    cout << minmp << endl;

    return 0;
}

int bitCount(int bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);    //  2bitごとに計算
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);    //  4bitごとに計算
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);    //  8bitごとに計算
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);    //  16ビットごとに計算   
    return (bits & 0x0000ffff) + (bits >> 16);    //  32ビット分を計算   
}
int mpown(int m,int n){
    if(n==0)return 1;
    else if(n==1) return m;
    else{
        int temp=mpown(m,n/2);
        return temp*temp*(n&1?m:1);
    }
}