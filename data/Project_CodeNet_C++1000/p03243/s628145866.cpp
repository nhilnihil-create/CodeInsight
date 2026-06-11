    #include <iostream>
    #include <string>
    #include <vector>
    #include <math.h>
    using namespace std;
     
    int main() {
        int N;
        cin>>N;
        for(int i=0;i<900;i++){
            if((N+i)%111==0){
                cout<<N+i;
                return 0;
            }
        }
    }