        #include<iostream>
        #include<vector>
        #include<string>
        #include<math.h>
        #include<algorithm>
        #include<cstring>//memset needs this head
        using namespace std;
        int canReach[2][16001];
        bool DP(vector<int> v,int t,int start){//v is the step vector of each axis
            memset(canReach,0,sizeof(canReach));
                canReach[0][8000+start]=1;//the initial place
            if(v.size()==0)
                return canReach[0][8000+t];
            int i;
            for(i=1;i<=v.size();i++){
                for(int j=0;j<=16000;j++){
                    canReach[i%2][j]=((j+v[i-1])>16000?0:canReach[(i-1)%2][j+v[i-1]])||((j-v[i-1])<0?0:canReach[(i-1)%2][j-v[i-1]]);
                }
            }
            return canReach[(i-1)%2][8000+t];
        }
        int main(){
            string S;
            int tx,ty;
            cin>>S>>tx>>ty;
            bool whichAxis=0;//the initial axis is x,1 is y;
            vector<int> vx;
            vector<int> vy;
            int count=0;
            for(auto c:S){
                if(c=='T'){
                    ((whichAxis==0)?vx:vy).push_back(count);
                    count=0;
                    whichAxis=!whichAxis;
                }
                else{
                    count++;
                }
            }
            ((whichAxis==0)?vx:vy).push_back(count);//that is important,the last several T's
           // tx-=vx[0];//the first several step in x have decided direction.That is an error
            int start=vx[0];
            vx.erase(vx.begin());
            if(DP(vx,tx,start)&&DP(vy,ty,0))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            return 0;
 
        }