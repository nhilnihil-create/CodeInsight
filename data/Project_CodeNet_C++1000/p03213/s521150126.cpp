#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main() {
    int N;
    cin>>N;
    map<int, int> primemap;
    vector<int> primearr;
    int tmp;
    for(int i=2;i<=N;++i){
        tmp = i;
        for(int j=2;tmp>1;++j){
            while(tmp%j==0){
                if(primemap[j]==0)primearr.push_back(j);
                tmp /= j;
                primemap[j]++;
            }
        }
    }
    int a=0, b=0, c=0, d=0, e=0, f=0, h=0;
    for(int i=0;i<primearr.size();++i){
        if(primemap[primearr[i]]>=74)a++;
        if(primemap[primearr[i]]>=24)b++;
        else if(primemap[primearr[i]]>=2)c++;
        if(primemap[primearr[i]]>=14)d++;
        else if(primemap[primearr[i]]>=4)e++;
        if(primemap[primearr[i]]>=4)f++;
        else if(primemap[primearr[i]]>=2)h++;
    }
    cout<<f*(f-1)/2 * h + f*(f-1)/2*(f-2) + a + b*c + d*e + d*(d-1) + b*(b-1)<<endl;
}
