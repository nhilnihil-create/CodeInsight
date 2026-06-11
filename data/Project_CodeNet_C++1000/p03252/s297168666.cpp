#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    string S,T;
    cin>>S>>T;
    vector<int>a1;
    vector<int>b1;
    long long int f,g,i,j,t=0;
    map<char,int>a;
    for(i=0;S[i];i++)
        {f=a[S[i]];
        a[S[i]]++;
        a1.push_back(f+1);}
        sort(a1.begin(),a1.end());
             map<char,int>b;
     for(i=0;T[i];i++)
        {g=b[T[i]];
        b[T[i]]++;
        b1.push_back(g+1);}
        sort(b1.begin(),b1.end());
        for(j=0;j<i;j++)
        {
            if(a1[j]!=b1[j])
                {t=1;
            break;}
        }
       if(t==1)
            cout<<"No";
       else
        cout<<"Yes";

}


