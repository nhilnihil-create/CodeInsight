#include <bits/stdc++.h>
using namespace std;
bool graph[5][5];
int main(void){
    int a,b;
    for (int i=0;i<3;i++) {
        cin>>a>>b;
        graph[a][b]=true;
        graph[b][a]=true;
    }
    int flag=0;
    if (graph[1][2]==true) {
        if (graph[2][3]==true) {
            if (graph[3][4]==true) {
                flag=1;
            }
        } else if (graph[2][4]==true) {
            if (graph[4][3]==true) {
                flag=1;
            }
        }
    } else if (graph[1][3]==true) {
        if (graph[3][2]==true) {
            if (graph[2][4]==true) {
                flag=1;
            }
        } else if (graph[3][4]==true) {
            if (graph[4][2]==true) {
                flag=1;
            }
        }
    } else if (graph[1][4]==true) {
        if (graph[4][2]==true) {
            if (graph[2][3]==true) {
                flag=1;
            }
        } else if (graph[4][3]==true) {
            if (graph[3][2]==true) {
                flag=1;
            }
        }
    } else if (graph[2][1]==true) {
        if (graph[1][3]==true) {
            if (graph[3][4]==true) {
                flag=1;
            }
        } else if (graph[1][4]==true) {
            if (graph[4][3]==true) {
                flag=1;
            }
        }
    } else if (graph[2][3]==true) {
        if (graph[3][1]==true) {
            if (graph[1][4]==true) {
                flag=1;
            }
        } else if (graph[3][4]==true) {
            if (graph[4][1]==true) {
                flag=1;
            }
        }
    } else if (graph[2][4]==true) {
        if (graph[4][1]==true) {
            if (graph[1][3]==true) {
                flag=1;
            }
        } else if (graph[4][3]==true) {
            if (graph[3][1]==true) {
                flag=1;
            }
        }
    } else if (graph[3][1]==true) {
        if (graph[1][2]==true) {
            if (graph[2][4]==true) {
                flag=1;
            }
        } else if (graph[1][4]==true) {
            if (graph[4][2]==true) {
                flag=1;
            }
        }
    } else if (graph[3][2]==true) {
        if (graph[2][1]==true) {
            if (graph[1][4]==true) {
                flag=1;
            }
        } else if (graph[2][4]==true) {
            if (graph[4][1]==true) {
                flag=1;
            }
        }
    } else if (graph[3][4]==true) {
        if (graph[4][1]==true) {
            if (graph[1][2]==true) {
                flag=1;
            }
        } else if (graph[4][2]==true) {
            if (graph[2][1]==true) {
                flag=1;
            }
        }
    } else if (graph[4][1]==true) {
        if (graph[1][2]==true) {
            if (graph[2][3]==true) {
                flag=1;
            }
        } else if (graph[1][3]==true) {
            if (graph[3][2]==true) {
                flag=1;
            }
        }
    } else if (graph[4][2]==true) {
        if (graph[2][1]==true) {
            if (graph[1][3]==true) {
                flag=1;
            }
        } else if (graph[2][3]==true) {
            if (graph[3][1]==true) {
                flag=1;
            }
        }
    } else if (graph[4][3]==true) {
        if (graph[3][1]==true) {
            if (graph[1][2]==true) {
                flag=1;
            }
        } else if (graph[3][2]==true) {
            if (graph[2][1]==true) {
                flag=1;
            }
        }
    }
    if (flag==1) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}