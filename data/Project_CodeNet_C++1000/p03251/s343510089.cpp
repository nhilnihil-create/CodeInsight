    #include <iostream>
    #include <string>
    #include <vector>
    #include <math.h>
    using namespace std;
     
    int main() {
        int N,M,X,Y;
        cin>>N>>M>>X>>Y;
        int P[N];
        int maxp=-100;
        for(int i=0;i<N;i++){
            cin>>P[i];
            if(P[i]>maxp){
                maxp=P[i];
            }
        }
        int Q[M];
        int minq=100;
        for(int j=0;j<M;j++){
            cin>>Q[j];
            if(Q[j]<minq){
                minq=Q[j];
            }
        }
        if(X<Y){
            if(maxp<minq){
                if(maxp>=X & minq<=Y){
                    cout<<"No War"<<endl;
                    return 0;
                }
                else{
                    cout<<"War"<<endl;
                    return 0;
                }
            }
            else{
                cout<<"War"<<endl;
                return 0;
            }
        }
        else{
            cout<<"War"<<endl;
            return 0;
        }
    }