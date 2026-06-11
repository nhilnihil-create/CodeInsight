#include <iostream>
#include <cmath>


using namespace std;


int main(){
   int X, Y, N, M,peaceCount;

   cin>>N;
   cin>>M;
   int arrayX[N], arrayY[M];
   cin>>X;
   cin>>Y;

   for(int i=0; i<N; i++){
        cin>>arrayX[i];
   }
   for(int i=0; i<M; i++){
        cin>>arrayY[i];
   }
   for(int i=X+1; i<=Y; i++){
        peaceCount=0;
        for(int j=0; j<N; j++){
                for(int k=0; k<M; k++){
                    if(i>arrayX[j] && i<=arrayY[k]){
                        peaceCount++;
                    }
                }
            }
        if (peaceCount==M*N){
            cout<<"No War"<<endl;
            break;
        }
   }
   if (peaceCount!=M*N){
        cout<<"War"<<endl;
   }
return 0;
   }

