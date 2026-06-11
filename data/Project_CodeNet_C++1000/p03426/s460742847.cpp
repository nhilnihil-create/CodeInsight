



 
//                                     ```..-------..```...``                                         
//                                  ``.-:::/://:::::::--.-----.`                                      
//                                `.-:://+++ooooooo++/:--:--.----.                                    
//                              `.--:/++oosyyyyyyso+//+o+/://----:-`                                  
//                             `.-:/++osyyhhddddddhhhhhyyysoo+++///-                                  
//                            `-::/+osyyhhhdddddmmmmmmmddddddhhyss+/.                                 
//                           `.-:+ossyyhhdddddddmmmmmmmmmddmdddhhyso/`                                
//                           `-:/+syyhhhhhhhhhhhhdmmmmmmmmmmmddddhys+.                                
//                          `.-:/osyhhyyssoo+oooosyhdmmmmmmmmmmmmdhso:                                
//                          .-:/+oyyso/////:://///++oydhhhhddddmmdhyo-`                               
//                          .-/+oss+/::::::::::::////+o+++oosshdddhy+`                                
//                          .:/+oo+:------------:::://////++++oshdhs/                                 
//                          `:/+/--.............----::::///+++++ohho.                                 
//                           -::-....-::://:---:------:::/+++++//os:                                  
//                         ```:/:--::://::/+++so+//+ossyyhhhhhys+:+`                                  
//                        ``..:/..--://o++oooooshyydhoossyyyssso+/+/.                                 
//                         ..---..-:/+:osyossooyyoshysyyydhysyo/:::o.                                 
//                         `.-..``.--:://+++ooyo-.-+hsssssysoo+/:-::                                  
//                         `.-.``````..---::/+/`  `.+s///++++/::--/.                                  
//                          `..``````````.-:/-`     `/+:::::----.-:`                                  
//                           `-``````````.-:.`      `.::::::::-----                                   
//                            ..`.```.....-:...````...--...-----.-`                                   
//                            `-........-..-/oso::+o+/-..------.-.                                    
//                             .-.....-:::-:oyhhoshhso:-----..--:                                     
//                             `---...:+oooo+oososssssosso:-.-::.                                     
//                              `--...-://++++++/++++soooo:--:/.                                      
//                               .::-.-:::::://///////::/:--::`                                       
//                               `-/////::::/++oo++/:::::://-`                                        
//                               `.:/+++//::://+///:://+++/.                                          
//                             ``..-://ooo++/++o+++++ooo+-`                                           
//                           ````..--::/+ooooooooooooo+/-.                                            
//                             `....--:::///+++++++//:::---                                           
//                             ``...---::::::///////::::::.`                                          
//                               `...----::::::::::::::::.````                                        
//                                 `...--::::::::/:::::-`````                                         
//                                   ``..------:::::---.````                                     .--.`
//                                     ``..-----..-:-```                                        .:++++
//                                        `````..``.`                                         `-://///
//                                             ``                                             --:///++
//                                                                                           `-:://+++
//                                                                                            `-:///++
//                                                                                             `-::/++
//                                                                                               .-:/+
//                                                                                                `.:/
//                                                                                                    
//                                                                                                    
//                                                                                                    
//                                      ````                                                          
//`````````                          ```````````                          ````````                    
//``````````````````````````       ```````````````````````````````  ``````......```                   
//
#include<bits/stdc++.h>
 
 
using namespace std;
 
#define int long long 
#define pb push_back
#define FAST   ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define TIC 	int tt = (int) clock();
 
#define TOK   cerr << "TIME = " << (double)(clock() - tt) / CLOCKS_PER_SEC << endl;
 
int kiran_bhanushali[29][7][20];
 
int32_t main(){
 
	int t=1;
	//cin>>t;
	while(t--){
        int h ,w , d;
        cin>>h>>w>>d;

        vector<vector<int>> a(h,vector<int>(w));
        
        vector<int> x(h*w+1),y(h*w+1);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>a[i][j];
                x[ a[i][j] ] = i;
                y[ a[i][j] ] =  j;
            }
        }
        
        vector<int> dp(h*w+1,0);

        for(int i=d+1;i<=h*w;i++){
            dp[i] = dp[i-d]+ abs( x[i] - x[i-d]) + abs( y[i] - y[i-d]);
        }

        int q;
        cin>>q;

        while(q--){
            int l,r;
            cin>>l>>r;
            if( (r-l)%d==0 ){
                cout<<dp[r]-dp[l]<<endl;
            }else{
                cout<<"-1"<<endl;
            }
        }

    
	}
 
    return 0;
}
