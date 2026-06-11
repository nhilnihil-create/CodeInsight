    #include <iostream>
    #include <string>
    #include <vector>
    #include <math.h>
    using namespace std;
     
    int main() {
        int N,T;
        cin>>N>>T;
        int P[N];
        int min=10000;
        for(int i=0;i<N;i++){
            int c,t;
            cin>>c>>t;
            if(t<=T){
                P[i]=c;
                if(min>P[i]){
                    min=P[i];
                }
            }
            else{
                P[i]=10000;
            }
        }
        if(min==10000){
            cout<<"TLE"<<endl;
        }
        else {
            cout<<min<<endl;
        }
    }