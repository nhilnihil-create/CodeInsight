#include<bits/stdc++.h>
using namespace std;

std::vector<int> va(101, 0);
std::vector<int> vb(101, 0);

void enum_divisors(long long N, int aorb) {
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            if(aorb){
                va[i]++;
                if (N/i != i)va[N/i]++;
            }else{
                vb[i]++;
                if (N/i != i)vb[N/i]++;
            }

        }
    }  
    return ;
}

int main() {
    long long a,b,k;
    cin >>a>>b>>k;
    enum_divisors(a, 1);
    //for (int x:va) cout << x << " ";
    //cout<<endl;
    enum_divisors(b, 0);
    //for (int x:vb) cout << x << " ";
    int cnt=0;
    for(int i=100;i>=1;i--){
        if(va[i]>0&&vb[i]>0){
            cnt++;
            if(cnt==k){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}