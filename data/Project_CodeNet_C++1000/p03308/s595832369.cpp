#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC100(void);
void ABC101(void);
void ABC102(void);
void ABC103(void);
void ABC104(void);
void ABC105(void);
void ABC106(void);
void ABC107(void);
void ABC108(void);
void ABC109(void);

int main(void){
    ABC102();
}

void ABC102(){
    int n,i;
    cin>>n;
    vector<int> vec(n);
    for(i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    cout<<vec[n-1]-vec[0]<<endl;
}
