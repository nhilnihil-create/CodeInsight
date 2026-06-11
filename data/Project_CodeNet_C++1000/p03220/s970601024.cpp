#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define nl printf("\n");
#define ll long long int

char f,g;
bool flag;
pair < int ,int > pi;
map < int , int > mp;
vector < int > v,va,vb;
int arr[sz],brr[sz],crr[sz];



int main(){

    double a,b,c,d,temp=INT_MAX,ans=INT_MAX,temp2;
    int n,m, i,j,k, x=0,y=0,z=0,idx;

    cin>>n>>a>>b;
    for(i=1; i<=n; i++){
        cin>>c;

        temp=a-c*0.006;
        temp2=(temp-b);
        if(temp2<0)
            temp2*=-1.0;
        //cout<<temp2<<endl;

        if(temp2<ans){
            ans=temp2;
            idx=i;
        }
    }
    cout<<idx<<endl;



    return 0;

}