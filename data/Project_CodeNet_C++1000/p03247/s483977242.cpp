#include <iostream>
#define INF 31381059609LL


using namespace std;



int main(void){
    int N;
    scanf("%d",&N);
    long long tate[N],yoko[N];
    for(int i=0;i<N;i++){scanf("%lld%lld",&yoko[i],&tate[i]);tate[i]*=-1;yoko[i]*=-1;}
    long long int po=(tate[0]+yoko[0]);
    if(po<0)po*=-1;
    po%=2;
    for(int i=1;i<N;i++){
        long long tmp=(tate[i]+yoko[i]);
        if(tmp<0)tmp*=-1;
        if(tmp%2!=po){
            printf("-1");
            return 0;
        }
    }
     printf("40\n");
    long long int unti=3;
    if(po==1)printf("2 1 ");
    else printf("1 1 ");
    for(int i=0;i<19;i++){
        printf("%lld %lld ",unti,unti);
        unti*=3;
    }
    printf("\n");
    for(int i=0;i<N;i++){
        long long unko=3;
        if(po==1){
            if((tate[i]+INF)%unko==0&&(yoko[i]+INF)%unko==0){printf("UU");tate[i]+=3;}
            else if((tate[i]+INF)%unko==0&&(yoko[i]+INF)%unko==(long long)(unko/3)){
                printf("LR");
                yoko[i]--;
            }
            else if((tate[i]+INF)%unko==0&&(yoko[i]+INF)%unko==((long long)(unko/3))*2){
                printf("RL");
                yoko[i]++;
            }
            else if((tate[i]+INF)%unko==(long long)(unko/3)&&(yoko[i]+INF)%unko==0){
                printf("DU");
                tate[i]--;
            }
            else if((tate[i]+INF)%unko==((long long)(unko/3))*2&&(yoko[i]+INF)%unko==0){
                printf("UD");
                tate[i]++;
            }
            else if((tate[i]+INF)%unko==(long long)(unko/3)&&(yoko[i]+INF)%unko==(long long)(unko/3)){
                printf("UL");
                yoko[i]--;
                tate[i]+=2;
            }
            else if((tate[i]+INF)%unko==(long long)(unko/3)&&(yoko[i]+INF)%unko==((long long)(unko/3))*2){
                printf("UR");
                yoko[i]++;
                tate[i]+=2;
            }
            else if((tate[i]+INF)%unko==((long long)(unko/3))*2&&(yoko[i]+INF)%unko==(long long)(unko/3)){
                printf("DL");
                yoko[i]--;
                tate[i]-=2;
            }
            else if((tate[i]+INF)%unko==((long long)(unko/3))*2&&(yoko[i]+INF)%unko==((long long)(unko/3))*2){
                printf("DR");
                yoko[i]++;
                tate[i]-=2;
            }
        }
        //long long unko=3;
        if(po==1)unko=9;
        for(int j=0;j<20-po;j++){
            if((tate[i]+INF)%unko==0&&(yoko[i]+INF)%unko==0){printf("UD");}
            else if((tate[i]+INF)%unko==0&&(yoko[i]+INF)%unko==(long long)(unko/3)){
                printf("RR");
                yoko[i]+=((long long)(unko/3))*2;
            }
            else if((tate[i]+INF)%unko==0&&(yoko[i]+INF)%unko==((long long)(unko/3))*2){
                printf("LL");
                yoko[i]-=((long long)(unko/3))*2;
            }
            else if((tate[i]+INF)%unko==(long long)(unko/3)&&(yoko[i]+INF)%unko==0){
                printf("UU");
                tate[i]+=((long long)(unko/3))*2;
            }
            else if((tate[i]+INF)%unko==((long long)(unko/3))*2&&(yoko[i]+INF)%unko==0){
                printf("DD");
                tate[i]-=((long long)(unko/3))*2;
            }
            else if((tate[i]+INF)%unko==(long long)(unko/3)&&(yoko[i]+INF)%unko==(long long)(unko/3)){
                printf("DL");
                yoko[i]-=(long long)(unko/3);
                tate[i]-=(long long)(unko/3);
            }
            else if((tate[i]+INF)%unko==(long long)(unko/3)&&(yoko[i]+INF)%unko==((long long)(unko/3))*2){
                printf("DR");
                yoko[i]+=(long long)(unko/3);
                tate[i]-=(long long)(unko/3);
            }
            else if((tate[i]+INF)%unko==((long long)(unko/3))*2&&(yoko[i]+INF)%unko==(long long)(unko/3)){
                printf("UL");
                yoko[i]-=(long long)(unko/3);
                tate[i]+=(long long)(unko/3);
            }
            else if((tate[i]+INF)%unko==((long long)(unko/3))*2&&(yoko[i]+INF)%unko==((long long)(unko/3))*2){
                printf("UR");
                yoko[i]+=(long long)(unko/3);
                tate[i]+=(long long)(unko/3);
            }
            // printf("ERROR:%lld\n",tate[i]);
            unko*=3;
        }
        printf("\n");
    }
    return 0;
}
