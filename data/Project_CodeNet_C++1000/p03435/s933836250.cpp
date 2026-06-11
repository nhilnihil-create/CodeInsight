    #include <bits/stdc++.h>
    #define f(i,j,k) for(int i=j;i<k;i++)
    #define f2(i,j,k) for(int i=j;i>k;i--)
    using namespace std;
    int main(){
        long long a[3][3],ans=0;
        f(i,0,3){
            f(j,0,3){
                cin>>a[i][j];
                ans+=a[i][j];
            }
        }
        if(ans%3!=0){
            cout<<"No"<<endl;
            return 0;
        }
        long long d[6];
        d[0]=a[0][0]+a[1][1]+a[2][2];
        d[1]=a[0][0]+a[1][2]+a[2][1];
        d[2]=a[0][1]+a[1][0]+a[2][2];
        d[3]=a[0][1]+a[1][2]+a[2][0];
        d[4]=a[0][2]+a[1][0]+a[2][1];
        d[5]=a[0][2]+a[1][1]+a[2][0];
        f(i,0,6){
            if(d[i]!=ans/3){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
        return 0;
    }